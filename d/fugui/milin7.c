#include <ansi.h>
inherit ROOM;
#include "milin.h" 
void create()
{
        set("short", HIR"����"NOR); 
        set("long", @LONG
����һƬ���֣���Χ��ľ������������Ʊ��գ����ܻ�谵����������һЩ˵
�������ֵĺ�ɫҰ����������Ҷ�̵أ�����ȥɳɳ���죬���һ�ŵ�һ�ŵ���ǰ��
����������Щ���ģ��������·�˰ɡ�
LONG); 
        set("type","forest");
        set("outdoors", "fugui");
        set("attribute","huo");
        set("exits",([
                "east":__DIR__"milin8",
                "south":__DIR__"milin12",
                "west":__DIR__"milin6",
                "north":__DIR__"milin2",
        ]) ); 
        set("coor/x",-610);
        set("coor/y",170);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_leave","leave");
} 
int do_leave(string arg)
{
        object room;
        this_player()->add("milin_walk",1);
        if(random(this_player()->query("milin_walk"))>30) 
        {
                if(random(100)>99)
                {
                        room=find_object(__DIR__"tomb");
                        if(!room) room=load_object(__DIR__"tomb");
                        tell_object(environment(this_player()),"��Ӱһ����$N�����ˡ�\n",this_player());
                   this_player()->move(room);
                        return 1;
                }
                else 
                {
                        room=find_object(__DIR__"shandao3");
                        if(!room) room=load_object(__DIR__"shandao3");
                        tell_object(environment(this_player()),"��Ӱһ����$N�����ˡ�\n",this_player());
                        tell_object(room,"$N�����ɻ�Ĵ����������˳�����һ���׳յ����ӡ�");
                        this_player()->move(room);
                        return 1;
                }
        }
        return 0;
} 
