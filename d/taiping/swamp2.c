#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
��������쵽�ķ��кü���Զ������ȫ�ǳ�ʪ�Ĳݵغ�һƬ���࣬���泤����
���Ӻ����ҵİ�����«έ�ܸߣ����ų�����Ҷ�ӣ��������ɫ��ë������������Ƥ
�װ׵ģ���ϸϡ���Ҷ�ӹ������ϡ�����в�����궼��һ�㱡�������š�
LONG
        );
        set("exits", ([ 
        //����ȥ̫ƽ���·����ӵ����˹����غͼ�����·��·����
//                "east": __DIR__"swamp1",
		"east": __DIR__"house6",
		"south": "/d/eren/kunlun1",
                "west": __DIR__"swamp3",
        ]));
        set("outdoors", "taiping");
        set("item_desc", ([
                    
        ]));
        set("toad",3);
        set("coor/x",-990);
        set("coor/y",150);
        set("coor/z",0);
        setup();
}  
void init()
{
        object me, here; 
        me = this_player();
        here = this_object(); 
        if( random(query("toad"))> 0 && userp(me) && time() - query("last_comeout") > 180
                && !present("toad",this_object())) {
                set("last_comeout", time() );
                remove_call_out("toad_out");
                call_out("toad_out", 6+random(3)); 
                tell_object(me, "����ý�����������ƺ��ȵ���ʲô���\n");
        }
} 
void toad_out()
{
   object toad, here;
        here = this_object(); 
        add("toad", -1);
        toad = new(__DIR__"npc/toad");
        toad->move(here);
        message("vision", YEL"�ݴ����Ȼ������һֻ��󡡣\n"NOR, here);
        return;
} 
