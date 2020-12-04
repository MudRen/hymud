#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "ԭʼ����");
        set("long", @LONG
������һƬ�ڰ����ڰ��г����˸�ʽ������Σ�գ�ÿһ�ֶ�����
�����������ڴ�������ʧ�˷��򣬼��ʾ�����������
LONG
        );
        set("exits", ([
                "north" : __DIR__"forest2",
                "south" : __DIR__"forest1",
                "east" : __DIR__"forest5",
                "west" : __DIR__"forest6",
        ]));
        set("outdoors", "ghost");
        set("NONPC",1);
        set("coor/x",-1190);
        set("coor/y",-50);
        set("coor/z",-10);
        setup();
} 
void init(){
        object me;
        me = this_player();
        if(me->query("family/family_name")=="����ɽׯ" || me->query_temp("marks/know_ghost")){
                tell_object(me, HIG"��ǰ��ɫ�ƺ���Щ��Ϥ������ϡ�ǵ����Ϸ��ĸߴ�������ɽ�¡�\n\n"NOR);
                set("exits/southup",__DIR__"forest9");
        }
} 
int valid_leave(object obj, string dir){
        object room;
        if(dir == "southup" && (obj->query("family/family_name")=="����ɽׯ" ||
                        obj->query_temp("marks/know_ghost"))){
                message_vision("$N������ϸ����򣬼����ڴ���֮��ǰ�С�\n", obj);
                tell_object(obj, HIG"\n��ǰ��Ȼһ����һ��ɽ�³�������ǰ��\n"NOR);
                delete("exits/southup"); 
                room = find_object(__DIR__"forest9");
                if(!objectp(room)){
                   room = load_object(__DIR__"forest9");
                }
                obj->move(room);
                return notify_fail("");
        }
        else {delete("exits/southup"); }
        return 1;
} 
void reset()
{
        ::reset();
        if(query("exits/southup"))
                delete("exits/southup");
        set("exits", ([
                "north" : __DIR__"forest2",
                "south" : __DIR__"forest1",
                "east" : __DIR__"forest5",
                "west" : __DIR__"forest6",
        ]));
}     
