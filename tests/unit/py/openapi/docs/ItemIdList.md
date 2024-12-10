# ItemIdList


## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**op** | **str** |  | [optional] 
**reg_code** | **str** |  | [optional] 
**parent_uuid** | **str** |  | [optional] 
**op_uuid** | **str** |  | [optional] 
**op_kind** | **str** |  | [optional] 
**op_seq** | **int** |  | [optional] [default to 0]
**op_page** | **int** |  | [optional] [default to 0]
**records** | [**List[ItemId]**](ItemId.md) |  | [optional] 
**filter** | [**List[ItemId]**](ItemId.md) |  | [optional] 

## Example

```python
from openapi_client.models.item_id_list import ItemIdList

# TODO update the JSON string below
json = "{}"
# create an instance of ItemIdList from a JSON string
item_id_list_instance = ItemIdList.from_json(json)
# print the JSON string representation of the object
print(ItemIdList.to_json())

# convert the object into a dict
item_id_list_dict = item_id_list_instance.to_dict()
# create an instance of ItemIdList from a dict
item_id_list_from_dict = ItemIdList.from_dict(item_id_list_dict)
```
[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


