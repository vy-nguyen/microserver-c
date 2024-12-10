# StatElement


## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**item_id** | [**ItemId**](ItemId.md) |  | 
**peer_id** | [**ItemId**](ItemId.md) |  | [optional] 
**counter** | [**Counter**](Counter.md) |  | [optional] 

## Example

```python
from openapi_client.models.stat_element import StatElement

# TODO update the JSON string below
json = "{}"
# create an instance of StatElement from a JSON string
stat_element_instance = StatElement.from_json(json)
# print the JSON string representation of the object
print(StatElement.to_json())

# convert the object into a dict
stat_element_dict = stat_element_instance.to_dict()
# create an instance of StatElement from a dict
stat_element_from_dict = StatElement.from_dict(stat_element_dict)
```
[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


