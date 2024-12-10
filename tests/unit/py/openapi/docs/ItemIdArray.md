# ItemIdArray


## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**item_key** | [**ItemKey**](ItemKey.md) |  | 
**item_ids** | [**List[ItemId]**](ItemId.md) |  | 

## Example

```python
from openapi_client.models.item_id_array import ItemIdArray

# TODO update the JSON string below
json = "{}"
# create an instance of ItemIdArray from a JSON string
item_id_array_instance = ItemIdArray.from_json(json)
# print the JSON string representation of the object
print(ItemIdArray.to_json())

# convert the object into a dict
item_id_array_dict = item_id_array_instance.to_dict()
# create an instance of ItemIdArray from a dict
item_id_array_from_dict = ItemIdArray.from_dict(item_id_array_dict)
```
[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


