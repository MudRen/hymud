 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
��ǰһ���������������̲�������Ȫˮ�Ը�ɽʯ����Ȼ���£����һ�����
ɽ´������ұ��пգ�״����ٵ���ʯ�ϣ����������ˣ����ˡ��ö����н����
���졣���й�ʫ�޵���ȴ��������ϸ������ʮ���Ҿ㲻�ڡ���
LONG
        );
    set("exits", ([ 
                "east"  : __DIR__"sandie",
        ]));
        set("objects", ([
        __DIR__"obj/stone3" : 1,
                        ]) );
        set("outdoors", "huangshan");
        set("coor/x",-570);
        set("coor/y",-520);
        set("coor/z",0);
        set("mingxuan", 1);
        setup();
} 
void init() {
        add_action("do_search", "search");
} 
int do_search(){
        object me, stone;
        
        me = this_player();     
        if (me->is_busy())
                return notify_fail("��������æ��\n");
        me->start_busy(1);
        if (me->query("marks/��ɽ����Ȫ") && query("mingxuan",1)) {
                message_vision("$N����ϸϸ����Ȫ���±�����Ѱ��\n", me);
                message_vision("$N������ʯ��һ����Щ�ɶ��� ������һ�⣬������������\n", me);
                stone = new(__DIR__"obj/ystone");
                stone->move(me);
                set("mingxuan",0);
           return 1;
        } 
        tell_object(me,"�����������һ�󣬽��ʲôҲû�ҵ���\n");
        return 1;
}  
void reset(){
        ::reset();
        if (!random(4)) set("mingxuan",1);
}  
                      
