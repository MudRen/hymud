//box.c.��ϻ
//data:1997.12.28
//by dan

#include <ansi.h>
#include <localtime.h>

inherit ITEM;

void create()
{
        seteuid(getuid());
        seteuid(geteuid());
        set_name("��ϻ", ({ "jian xia", "xia", "box" }));
        set_weight(3000);
        set_max_encumbrance(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
      set("long", "һֻ��ʽ���ӵ�ʯϻ���Ͽ���<<��ϻ>>����,�и�(top)�Ϻ��ر��м�����Ŧ....\n"+
              "------------------------------------------------------------\n"+
              "|                                                          |\n"+
              "|       "+BLINK HIY"��"NOR+"      "+BLINK HIC"ľ"NOR+"      "+BLINK HIB"ˮ"NOR+"      "+
                    BLINK  HIR"��"NOR+"      "+BLINK YEL"��"NOR+"      "+BLINK HIM"���"NOR+"       |\n"+
              "|                                                          |\n"+
              "------------------------------------------------------------\n");
                set("value", 80);
                set("dan",0);
                set("dan_number",1);
         }
}

int is_container() { return 1; }

void init()
{
    add_action("do_an","an");
}

int do_an( string arg )
{
    object me,ob,room;
    int time,hour,i,j,k;
    mixed *ltime;
    time = time();
    ltime = localtime( time*60 );
    hour = ltime[LT_HOUR];
    me = this_player();
    ob = this_object();
    room = environment( me );
    j = ob ->query("dan");
    if ( !arg )
    return notify_fail("�㰴��һ�º��ӣ��ܽ�ʵ���ﲻ����˵....\n");
    if ( arg != "��" && arg != "ˮ" && arg != "ľ" && arg != "��" 
          && arg != "��" && arg != "���" )
    return notify_fail("��Ϲ��Щʲô.....?\n");
    j = j +1;
    k = 0;
    if ( arg == "��" && ( hour == 1||hour == 7||hour == 13||hour ==19))
    k = 1;
    if ( arg == "ľ" && ( hour == 2||hour == 8||hour == 14||hour ==20))
    k = 1;
    if ( arg == "ˮ" && ( hour == 3||hour == 9||hour == 15||hour == 21))
    k = 1;
    if ( arg == "��" && ( hour == 4||hour == 10||hour == 16||hour == 22))
    k = 1;
    if ( arg == "��" && ( hour == 5||hour == 11||hour == 17||hour == 23))
    k = 1;
    if ( arg == "���" && ( hour == 6||hour == 12||hour == 18||hour ==24 ))
    k = 1;
    if ( k == 0 )
    {
         ob ->set("dan",0);
         return notify_fail("�����ϵİ�Ŧ�ƺ���������˵....\n");
    }
    if ( hour != j )
    {
         ob-> set("dan",0);
         return notify_fail("�����ϵİ�Ŧһ�ɺи��ƺ��ɶ���һЩ,��һ��һ������....\n");
    }   
    write("�и�֨֨һ���죬�ƺ���Щ�ɶ�.....\n");
    if ( j < 24 )
    {
         ob ->set("dan",j);
         return 1;
    }
    ob ->set("dan",0);
    if( ob->query("dan_number")== 0 )
    return notify_fail("��ϻһ�±ſ�������ʲôҲû��....\n");
    write("��ϻһ�±ſ����������һ�ѱ���.....\n");
    new(__DIR__"jian4")->move( room );
    ob ->set("dan_number",0);
    return 1;     
}    

