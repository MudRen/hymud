 inherit ITEM;
void create()
{
        set_name("��������", ({ "book" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"��ս�Űܣ��Ű���ս��ˮ��ʯ�������Ƴ��롣����������̸д�ڵ���ʮ���������С�\n"
                );
                set("value", 260);
                set("material", "paper");
        }
        
}
     
