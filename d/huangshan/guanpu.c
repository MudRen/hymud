 // TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        int i;
        
    set("short", "����ͤ");
    set("long", @LONG
һ�������̽ǣ�������ɫ������Сͤ�ӣ��м����һ��ʯ�����ĸ�ʯ�ʣ�����
�������Զ�ۻ�ɽ��������֮һ�ġ�����Ȫ�����ɴ˿�����Ȫ��ֻ����̶�����ƶ�
���з�Ȫ��й�����������콵������ʱ������ɴ��������ʱ����ǧƥ����������
��ʣ�ʵ������ʤ�ա�
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"wenquan",
]));
        set("objects", ([
                __DIR__"npc/katai" : 1,
                            
       ]) );  
    set("outdoors", "huangshan");
        set("coor/x",-520);
        set("coor/y",-500);
        set("coor/z",20);
        setup();
} 
void init() { 
        add_action("do_look", "look");
} 
int do_look(string arg) {
        object me;
        int season, i;
        
        me = this_player(); 
        season = random(4)+1;
        if(!arg || arg != "waterfall" && arg != "����Ȫ" && arg != "�ٲ�") {
                return 0;       
        }
   if(!me->query_temp("state/sit")) {
                write("���������������ؿ�������Ȫ��\n");
                return 1;
        }
        if(season == 1 ) {
                write("ˮ��һƥ�����Ӱ��ɵĸ��¹��£��ڷ��ж����Ű�˿һ����ˮ��\n");
        } else if (season == 2 ) {
                write("������������ͤ����ٲ���ȥ��ֻ��ˮ�Ӱ��ɵĸ������£�\n");
                write("���������ڣ�������µ׵�ʯͷ�Ͻ�����һƬ��ɫ��ˮ��\n");
                call_out("water_drop", random(30), me);
        } else if (season == 3 ) {
                write("������������ͤ����ٲ���ȥ��ֻ��ˮ�Ӱ��ɵĸ������£�\n");
                write("���������ڣ�������µ׵�ʯͷ�Ͻ�����һƬ��ɫ��ˮ��\n");
                call_out("water_drop", random(30), me);
        } else if (season == 4 ) {
                write("ˮ��һƥ�����Ӱ��ɵĸ��¹��£��ڷ��ж����Ű�˿һ����ˮ��\n");
        } else {
                return 0;
        }
        return 1;
} 
void water_drop(object me) {
        int kar;
        kar = me->query_kar();
        if(objectp(me) && environment(me) == this_object()) {
                if(random(40) < kar) {
                        tell_object(me, "һ�󾢷紵�������α�����ˮ¶������������ϡ���̧��Ĩȥ���ϵ�ˮ�Ρ�\n");
                        message("vision", me->name() + "̧��������Ĩ��һ�ѡ�\n", environment(me), me);
me->set("����B/��ɽ_�ٲ�", 1+random(10));
                } else {
                        tell_object(me, "һ�󾢷紵��������ˮƮ����ͤ����ϡ�\n");
                }
        }
}   
int valid_leave(object who,string dir)
{
        if(who->query_temp("state/sit"))
                return notify_fail("���������أ������뿪����\n");
        return 1;
} 
