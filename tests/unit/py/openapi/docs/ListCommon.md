# ListCommon


## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**page_info** | [**PageInfo**](PageInfo.md) |  | 
**extras** | [**List[ItemId]**](ItemId.md) |  | [optional] 

## Example

```python
from openapi_client.models.list_common import ListCommon

# TODO update the JSON string below
json = "{}"
# create an instance of ListCommon from a JSON string
list_common_instance = ListCommon.from_json(json)
# print the JSON string representation of the object
print(ListCommon.to_json())

# convert the object into a dict
list_common_dict = list_common_instance.to_dict()
# create an instance of ListCommon from a dict
list_common_from_dict = ListCommon.from_dict(list_common_dict)
```
[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


