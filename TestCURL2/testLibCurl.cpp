#include <iostream>
#include <string>
#include <curl/curl.h>
#include <Poco/JSON/JSON.h>
#include <Poco/JSON/Parser.h>
#include <Poco/Dynamic/Var.h>
#include <fstream>

using namespace std;
using namespace Poco::JSON;

string GetValue(Object::Ptr aoJsonObject, const char *aszKey) {
    Poco::Dynamic::Var loVariable;
    string lsReturn;
    string lsKey(aszKey);

    // Get the member Variable
    //
    loVariable = aoJsonObject->get(lsKey);

    // Get the Value from the Variable
    //
    lsReturn = loVariable.convert<std::string>();

    return lsReturn;
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

static size_t WriteFileBack(void *contents, size_t size, size_t nmemb, FILE *stream) {
    size_t written;
    written = fwrite(contents, size, nmemb, stream);
    return written;
}

int main(void)
{
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://packagist.org/packages/yiisoft/yii2.json");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }

  Parser parser;

  Poco::Dynamic::Var ParsedJson = parser.parse(readBuffer);
  Poco::Dynamic::Var ParsedRet = parser.result();
  Object::Ptr jsonObject = ParsedRet.extract<Object::Ptr>();

  cout << "Package : " << GetValue(jsonObject, "package") << endl;

  curl = curl_easy_init();
  if(curl) {
    FILE *fp = fopen("output.txt", "wb");
    curl_easy_setopt(curl, CURLOPT_URL, "https://packagist.org/packages/yiisoft/yii2.json");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteFileBack);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    fclose(fp);
  }

  return 0;
}
