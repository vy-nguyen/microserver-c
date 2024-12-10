# ItemKey


## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**tag_uuid** | **str** |  | [default to '']
**elem_uuid** | **str** |  | [optional] [default to '']
**owner_uuid** | **str** |  | [default to '']
**kind** | [**IdKind**](IdKind.md) |  | 
**seq_no** | **int** |  | [default to 0]

## Example

```python
from openapi_client.models.item_key import ItemKey

# TODO update the JSON string below
json = "{}"
# create an instance of ItemKey from a JSON string
item_key_instance = ItemKey.from_json(json)
# print the JSON string representation of the object
print(ItemKey.to_json())

# convert the object into a dict
item_key_dict = item_key_instance.to_dict()
# create an instance of ItemKey from a dict
item_key_from_dict = ItemKey.from_dict(item_key_dict)
```
[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


