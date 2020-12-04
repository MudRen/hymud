#include <ansi.h>
#include <room.h> 
inherit ROOM;
int drop_him(object me);
void create()
{
        object san, sna;
        set("short", "��Į��ɳ");
        set("long", @LONG
�����ڴ��ڿ������¯��ɳĮ�У��ȵ�����������͸������������������
�ķ�������ʲôҲ���������������۹����ķ�ɳ����ʲôҲ����������ؼ�
�·�ֻʣ����һ���ˡ�����»�����������ɳ�������ñ����ĸо���
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"desert6",
  "north" : "/d/guanyin/entrance",
  "south" : __DIR__"desert1",
  "east"  : __DIR__"desert8",
  "down"  : __DIR__"quicksand2",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
                __DIR__"obj/hu-blade" : 1,
                 __DIR__"obj/skeleton" : 1,
                "/clone/money/silver": 1,
        ]) ); 
        set("outdoors", "quicksand"); 
        set("coor/x",-1080);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        san = present("sand", this_object());
        sna = present("hu-blade", this_object());
        sna->move(san);
        sna = present("skeleton", this_object());
        sna->move(san);
        sna = present("silver", this_object());
        sna->move(san); 
} 
void init()
{       object ob;
        object jade;
        int water, food, bellicosity;
        string outexit;
        if( interactive( ob = this_player()))
        {
        water = ob->query("water");
        food = ob->query("food");
        bellicosity = ob->query("bellicosity");
        water -= (random(4)+ 1) * water / 10;
        food -= (random(2)+ 1) * water / 10;
        bellicosity += random(10);
        ob->set("water", water);
        ob->set("food", food);
        ob->set("bellicosity", bellicosity);    
        if( !objectp(jade = present("jade", ob)))
        {
                if( random(300)< 2)               drop_him(ob);
        }
        else
        {
                if( random(1000)< 1)    drop_him(ob);
        }
        }
        add_action("do_pull", "pull");
}
int drop_him(object me)
{
        me->start_busy(1);
        call_out("dropnow", 1, me);
        return 1; 
}
int dropnow(object me){
        if(environment(me) == this_object()){
        message_vision(HIW"$NͻȻ�е��ŵ�������ģ��޴�������", me);
        message_vision("$N���һ�������ã����������������ˡ�\n", me);
        message_vision("$N��������ɳ֮�У���\n"NOR, me);
        me->move(__DIR__"quicksand2");
    }
        return 1;
} 
int do_pull ( string arg)
{
        object me, who;
        object room;
        me = this_player();
        if ( !arg  ) return notify_fail("��Ҫ��˭������\n");
        room = load_object(__DIR__"quicksand2");
        if(!objectp(who = present(arg, room)) ||  !living(who))
        return notify_fail("��ɳ��û������ˡ�\n");
         message_vision(HIW"$N�þ�ȫ����������$n����ɳ�о��˳�����\n"NOR, me,who);
        who->move(__FILE__);
        return 1; 
}       
