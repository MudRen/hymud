// juan.c. ���Ƥ
//date:1997.8.28
//by dan   

#include <ansi.h>
#include <armor.h>
inherit WRISTS;   

void create()
{
        set_name(YEL"��Ƥ"NOR, ({ "yang pi","pi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ���ƾɵ���Ƥ����һЩ��ģ����ͼ��(tu). \n");
                set("unit", "��");
                set("value", 5);
        }
        set("dan_bi_1",random(4));
        set("dan_bi_2",random(4));
        set("dan_bi_3",random(4));
        set("dan_bi_4",random(4));
        set("dan_bi_5",random(4));
        set("dan_bi_6",random(4));
        set("dan_bi_7",random(4));
        set("dan_bi_8",random(4));
        set("dan_bi_9",random(4));
        setup();

}

void init()
{

  add_action("do_study","study");
}

int do_study(string arg)
{
    object me,ob;
    string msg,str;
    int i;
    me = this_player();
    ob = this_object();
    if ( arg != "tu" )
    return notify_fail("��Ƥ�ϳ���һЩģ����ͼ������ʲôҲû��\n");
    msg = "";
    for ( i = 1;i<= 9;i++)
    {
        str = "dan_bi_"+(string)i;
        if ( ob->query(str) == 0 )  msg += "��";   
        if ( ob->query(str) == 1 )  msg += "��";
        if ( ob->query(str) == 2 )  msg += "��";
        if ( ob->query(str) == 3 )  msg += "��";
    }
     msg += "\n";
    write( msg );
    ob->set("dan",0);
    return 1;
}

