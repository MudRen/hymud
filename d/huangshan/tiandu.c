 // TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�춼��");
        set("long", @LONG
�춼��������������Ϊ�վ���һ�����ųơ�Ⱥ������������Ϊ���϶��ᡣ����
·��������ɽ��͵�ʯ��������Χ���ĵ�ɽ����������Ȼ�����С����������족֮
�С�;����һʯ���磬���С��������������֣��ɴ˴����������������ƹַ壬ɽ
Ȫ�ɺ��������۵ס�
LONG
        );
        set("exits", ([ 
                "southdown"  : __DIR__"jiyu",
                "westdown" : __DIR__"yixian",
        ]));
        set("objects", ([
                __DIR__"npc/hong" : 1,
                __DIR__"npc/lu" :1,
        ]) );
    set("cloud", 0);
    set("outdoors", "huangshan");
        set("coor/x",-560);
    set("coor/y",-470);
        set("coor/z",40);
        setup();
} 
void init(){
        int i, dayTime;
        mixed *local;


        if((i = 1 || i = 2 || i = 3) && random(3)==0 && !query("cloud")) {
                remove_call_out("cloud");
                call_out("cloud", random(40));
        }
} 
void cloud(){
        object *inv, *players;
        int i;
        inv = all_inventory();
    players = filter_array(inv, (: interactive($1) :));
        message("vision", HIW"ͻȻ������󺣳�һ��ӿ����ת�����ܶ��ǰ�ãã����\n"NOR, players);
        for(i=0; i<sizeof(players); i++) {
                if (!players[i]->query("����B/��ɽ_�ƺ�")) {
                    players[i]->set("����B/��ɽ_�ƺ�",1+random(10));
                }
        }   
        set("cloud", 1);
}     
