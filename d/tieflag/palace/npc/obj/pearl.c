 inherit ITEM;
void create()
{
        set_name("�׻���", ({ "pearl" , "�׻���"}) );
        set_weight(1);
        set("explosive",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ǿ��ը�����׻���\n");
                set("value", 1000);
        }
}       
