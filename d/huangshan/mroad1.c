 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
���߻������ź�����ˮ�������ƺ��������ڿ������ŵ��ٲ�����Ϣ��Ȼ������
������Ȼ������ˮ�������ܲ��ɴ�أ�һƬ�������ⰻȻ�������������Ұ����
׺��䣬����Щɫ�ʣ�������ʯ̨���𼶶��ϣ���ɽ�������̻���       
LONG
        );
    set("exits", ([ 
                "northup" : __DIR__"jiulong",
                "southeast" : __DIR__"baizhang",
        ]));
        set("item_desc", ([
         ]) );
    set("outdoors", "huangshan");
    set("coor/x",-550);
        set("coor/y",-490);
    set("coor/z",10);
        setup();
}
void init() {
        object me;
        me = this_player();
        call_out("turtle_move", random(10), me);
        add_action("do_search", "search");
} 
int turtle_move(object me) {
        if (environment(me) == this_object()  && !me->query("stone_mark/gstone")) {
                if(me->query("marks/�޻�") && !present("green turtle", this_object()) && !random(20)) {
                        tell_object(me, "���ݴ����ƺ���ʲô��������һ�£�����Ϊ�Լ��ۻ��ˡ�\n"); 
                        me->set_temp("marks/search_turtle", 1);
                        return 1;
                }
        }  
  return 1;     
}
int do_search() {
        object me, ob;
   
        me = this_player();
        if (!me->query_temp("marks/search_turtle")) {
                return 0;
        }
        message("vision", me->name() + "�ڲݴ�����ϸѰ�ҡ�\n", environment(me), me);
        tell_object(me, "�㲦���ݴ���ϸѰ�ң���Ȼ����һֻ����������ϸϸ��ë�ڹ�����������\n"); 
        me->delete_temp("marks/search_turtle");
        ob = new(__DIR__"npc/turtle");
        if(objectp(ob)) {
                ob->move(this_object());
        }
        return 1;
}       
