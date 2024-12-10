# StatOperation


## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**item_key** | [**ItemKey**](ItemKey.md) |  | 
**signature** | [**Signature**](Signature.md) |  | 
**values** | [**List[StatElement]**](StatElement.md) |  | 

## Example

```python
from openapi_client.models.stat_operation import StatOperation

# TODO update the JSON string below
json = "{}"
# create an instance of StatOperation from a JSON string
stat_operation_instance = StatOperation.from_json(json)
# print the JSON string representation of the object
print(StatOperation.to_json())

# convert the object into a dict
stat_operation_dict = stat_operation_instance.to_dict()
# create an instance of StatOperation from a dict
stat_operation_from_dict = StatOperation.from_dict(stat_operation_dict)
```
[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


