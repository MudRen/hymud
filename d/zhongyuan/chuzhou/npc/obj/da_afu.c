// �󰢸� /d/city/chuzhou/npc/obj/da_afu.c
// by lala, 1997-12-16

inherit ITEM;

void create()
{
        set_name( "�󰢸�", ({"da afu", "afu", }));
        set_weight(50);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
һ�����ֵ�Ц���е����ˣ������������ز����Ǽ����˵ĺ����
LONG
    );
                set("unit", "��");
                set("value", 230);
        }
        setup();
}
