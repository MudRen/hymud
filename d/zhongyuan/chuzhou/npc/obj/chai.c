// �����Է��������ղ� /d/city/chuzhou/npc/obj/chai.c
// by lala, 1997-12-14

inherit ITEM;
void create()
{
        set_name("�ղ�",({"shao chai","chai"}));
        set("weight",2000);
    if (clonep())
        set_default_object(__FILE__);
    else 
   {
        set("unit","��");
            set("value", 30 + random(30) );
            set("long","һ�����ղ�\n");
    }       
}
