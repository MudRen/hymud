inherit ITEM;
void create()
{
    set_name("�Ѱ�", ({ "pu bao", "bag" }));
    set_weight(180);
    set("long", @LONG
�Ѳ��ǳ��ݵ��ز����������Ѳݽ��б�֯��Ҳ�ǳ��������е�һ���ֹ�ҵ���Ѱ�
�������е�һ����Ҫ�Ĳ�Ʒ�������˶�������װ�������ܷ��㡣
LONG
    );
    set_max_encumbrance(12000);
    if (clonep())
        set_default_object(__FILE__);
    else 
    {
        set("unit", "ֻ");
        set("value", 27);
    }
}

int is_container() { return 1; }
