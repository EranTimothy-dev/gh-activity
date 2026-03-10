#include "http.hpp"
#include <curl/curl.h>

static std::size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    buffer->append((char*)contents, size * nmemb);
    return size * nmemb;
} 

namespace http {

    std::string get(const std::string& url) {

        CURL *curl = curl_easy_init();
        if (!curl) {
            fprintf(stderr, "Failed to initialize curl\n");
            return "";
        }
        std::string response;

        // set URL for the request by converting std::string to C-style string ( const char* )
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        // set callback function to handle response data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        // write response data to our string variable
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        // set user agent to avoid 403 Forbidden error from GitHub API
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "gh-activity-cli/1.0");

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return "";
        }
        curl_easy_cleanup(curl);

        return response;
    }
}


