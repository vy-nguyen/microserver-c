# openapi_client.DefaultApi

All URIs are relative to *http://localhost:8080*

Method | HTTP request | Description
------------- | ------------- | -------------
[**auth_counter_post**](DefaultApi.md#auth_counter_post) | **POST** /auth/counter | Create counters having IDs from ItemIdArray.
[**auth_setcounter_post**](DefaultApi.md#auth_setcounter_post) | **POST** /auth/setcounter | Change counters for an itemKey
[**public_counter_post**](DefaultApi.md#public_counter_post) | **POST** /public/counter | Get counters for an itemId
[**public_counters_get**](DefaultApi.md#public_counters_get) | **GET** /public/counters | Get default set of counters.
[**test_get_get**](DefaultApi.md#test_get_get) | **GET** /test/get | A test get API.
[**test_setcounter_post**](DefaultApi.md#test_setcounter_post) | **POST** /test/setcounter | Set a counter with initial values.


# **auth_counter_post**
> StatList auth_counter_post(item_id_array)

Create counters having IDs from ItemIdArray.

This auth API creates a new counter set.

### Example


```python
import openapi_client
from openapi_client.models.item_id_array import ItemIdArray
from openapi_client.models.stat_list import StatList
from openapi_client.rest import ApiException
from pprint import pprint

# Defining the host is optional and defaults to http://localhost:8080
# See configuration.py for a list of all supported configuration parameters.
configuration = openapi_client.Configuration(
    host = "http://localhost:8080"
)


# Enter a context with an instance of the API client
with openapi_client.ApiClient(configuration) as api_client:
    # Create an instance of the API class
    api_instance = openapi_client.DefaultApi(api_client)
    item_id_array = openapi_client.ItemIdArray() # ItemIdArray | Counter data.

    try:
        # Create counters having IDs from ItemIdArray.
        api_response = api_instance.auth_counter_post(item_id_array)
        print("The response of DefaultApi->auth_counter_post:\n")
        pprint(api_response)
    except Exception as e:
        print("Exception when calling DefaultApi->auth_counter_post: %s\n" % e)
```



### Parameters


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **item_id_array** | [**ItemIdArray**](ItemIdArray.md)| Counter data. | 

### Return type

[**StatList**](StatList.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

### HTTP response details

| Status code | Description | Response headers |
|-------------|-------------|------------------|
**200** | Current values of the counter set. |  -  |

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **auth_setcounter_post**
> StatList auth_setcounter_post(stat_operation)

Change counters for an itemKey

This auth API changes counters owned by itemKey.

### Example


```python
import openapi_client
from openapi_client.models.stat_list import StatList
from openapi_client.models.stat_operation import StatOperation
from openapi_client.rest import ApiException
from pprint import pprint

# Defining the host is optional and defaults to http://localhost:8080
# See configuration.py for a list of all supported configuration parameters.
configuration = openapi_client.Configuration(
    host = "http://localhost:8080"
)


# Enter a context with an instance of the API client
with openapi_client.ApiClient(configuration) as api_client:
    # Create an instance of the API class
    api_instance = openapi_client.DefaultApi(api_client)
    stat_operation = openapi_client.StatOperation() # StatOperation | Stat operation

    try:
        # Change counters for an itemKey
        api_response = api_instance.auth_setcounter_post(stat_operation)
        print("The response of DefaultApi->auth_setcounter_post:\n")
        pprint(api_response)
    except Exception as e:
        print("Exception when calling DefaultApi->auth_setcounter_post: %s\n" % e)
```



### Parameters


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **stat_operation** | [**StatOperation**](StatOperation.md)| Stat operation | 

### Return type

[**StatList**](StatList.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

### HTTP response details

| Status code | Description | Response headers |
|-------------|-------------|------------------|
**200** | Counter stats for items changed by the op |  -  |

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **public_counter_post**
> StatList public_counter_post(item_id_array)

Get counters for an itemId

This public API sends list of itemIds to get counters for the itemId owner

### Example


```python
import openapi_client
from openapi_client.models.item_id_array import ItemIdArray
from openapi_client.models.stat_list import StatList
from openapi_client.rest import ApiException
from pprint import pprint

# Defining the host is optional and defaults to http://localhost:8080
# See configuration.py for a list of all supported configuration parameters.
configuration = openapi_client.Configuration(
    host = "http://localhost:8080"
)


# Enter a context with an instance of the API client
with openapi_client.ApiClient(configuration) as api_client:
    # Create an instance of the API class
    api_instance = openapi_client.DefaultApi(api_client)
    item_id_array = openapi_client.ItemIdArray() # ItemIdArray | Array of itemIds to retrieve counters

    try:
        # Get counters for an itemId
        api_response = api_instance.public_counter_post(item_id_array)
        print("The response of DefaultApi->public_counter_post:\n")
        pprint(api_response)
    except Exception as e:
        print("Exception when calling DefaultApi->public_counter_post: %s\n" % e)
```



### Parameters


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **item_id_array** | [**ItemIdArray**](ItemIdArray.md)| Array of itemIds to retrieve counters | 

### Return type

[**StatList**](StatList.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

### HTTP response details

| Status code | Description | Response headers |
|-------------|-------------|------------------|
**200** | Counter stats for items queried by the itemKey input |  -  |

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **public_counters_get**
> StatList public_counters_get()

Get default set of counters.

This public API gets list of default stat counters.

### Example


```python
import openapi_client
from openapi_client.models.stat_list import StatList
from openapi_client.rest import ApiException
from pprint import pprint

# Defining the host is optional and defaults to http://localhost:8080
# See configuration.py for a list of all supported configuration parameters.
configuration = openapi_client.Configuration(
    host = "http://localhost:8080"
)


# Enter a context with an instance of the API client
with openapi_client.ApiClient(configuration) as api_client:
    # Create an instance of the API class
    api_instance = openapi_client.DefaultApi(api_client)

    try:
        # Get default set of counters.
        api_response = api_instance.public_counters_get()
        print("The response of DefaultApi->public_counters_get:\n")
        pprint(api_response)
    except Exception as e:
        print("Exception when calling DefaultApi->public_counters_get: %s\n" % e)
```



### Parameters

This endpoint does not need any parameter.

### Return type

[**StatList**](StatList.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

### HTTP response details

| Status code | Description | Response headers |
|-------------|-------------|------------------|
**200** | Default counter stats. |  -  |

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **test_get_get**
> TestGetGet200Response test_get_get()

A test get API.

Test API to get something.

### Example


```python
import openapi_client
from openapi_client.models.test_get_get200_response import TestGetGet200Response
from openapi_client.rest import ApiException
from pprint import pprint

# Defining the host is optional and defaults to http://localhost:8080
# See configuration.py for a list of all supported configuration parameters.
configuration = openapi_client.Configuration(
    host = "http://localhost:8080"
)


# Enter a context with an instance of the API client
with openapi_client.ApiClient(configuration) as api_client:
    # Create an instance of the API class
    api_instance = openapi_client.DefaultApi(api_client)

    try:
        # A test get API.
        api_response = api_instance.test_get_get()
        print("The response of DefaultApi->test_get_get:\n")
        pprint(api_response)
    except Exception as e:
        print("Exception when calling DefaultApi->test_get_get: %s\n" % e)
```



### Parameters

This endpoint does not need any parameter.

### Return type

[**TestGetGet200Response**](TestGetGet200Response.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

### HTTP response details

| Status code | Description | Response headers |
|-------------|-------------|------------------|
**200** | A get test string. |  -  |

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **test_setcounter_post**
> TagAttr test_setcounter_post(tag_attr)

Set a counter with initial values.

This auth API create a new counter set.

### Example


```python
import openapi_client
from openapi_client.models.tag_attr import TagAttr
from openapi_client.rest import ApiException
from pprint import pprint

# Defining the host is optional and defaults to http://localhost:8080
# See configuration.py for a list of all supported configuration parameters.
configuration = openapi_client.Configuration(
    host = "http://localhost:8080"
)


# Enter a context with an instance of the API client
with openapi_client.ApiClient(configuration) as api_client:
    # Create an instance of the API class
    api_instance = openapi_client.DefaultApi(api_client)
    tag_attr = openapi_client.TagAttr() # TagAttr | Counter data.

    try:
        # Set a counter with initial values.
        api_response = api_instance.test_setcounter_post(tag_attr)
        print("The response of DefaultApi->test_setcounter_post:\n")
        pprint(api_response)
    except Exception as e:
        print("Exception when calling DefaultApi->test_setcounter_post: %s\n" % e)
```



### Parameters


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **tag_attr** | [**TagAttr**](TagAttr.md)| Counter data. | 

### Return type

[**TagAttr**](TagAttr.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

### HTTP response details

| Status code | Description | Response headers |
|-------------|-------------|------------------|
**200** | Current values of the counter set. |  -  |

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

