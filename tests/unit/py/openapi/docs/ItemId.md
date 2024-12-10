# ItemId


## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**uuid** | **str** |  | 
**kind** | [**IdKind**](IdKind.md) |  | 
**seq_no** | **int** |  | [default to 0]

## Example

```python
from openapi_client.models.item_id import ItemId

# TODO update the JSON string below
json = "{}"
# create an instance of ItemId from a JSON string
item_id_instance = ItemId.from_json(json)
# print the JSON string representation of the object
print(ItemId.to_json())

# convert the object into a dict
item_id_dict = item_id_instance.to_dict()
# create an instance of ItemId from a dict
item_id_from_dict = ItemId.from_dict(item_id_dict)
```
[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


