# StatList


## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**page** | [**ListCommon**](ListCommon.md) |  | 
**list** | [**List[Stats]**](Stats.md) |  | 

## Example

```python
from openapi_client.models.stat_list import StatList

# TODO update the JSON string below
json = "{}"
# create an instance of StatList from a JSON string
stat_list_instance = StatList.from_json(json)
# print the JSON string representation of the object
print(StatList.to_json())

# convert the object into a dict
stat_list_dict = stat_list_instance.to_dict()
# create an instance of StatList from a dict
stat_list_from_dict = StatList.from_dict(stat_list_dict)
```
[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


