 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        object con,item;
        set("short", "��ɽ��®");
        set("long", @LONG
�ò����׹��վ�����������ǰ����һ�����嶥��Ȼ�м�é�ݣ�����һ��������
���ҡ���ɽ��®�������ڳ���򵥣�һ�ź�ľ���Ϸ��ż��ᾭ����Ͳ��ϡ��ز�
�ż�ֻ�Ǻ���
LONG
        );
        set("exits", ([ 
          "south" : __DIR__"tiesuo",
        ]));
    set("objects", ([
        __DIR__"npc/mas1" : 1,
        __DIR__"npc/mas2" : 1,
         //       __DIR__"obj/xi" : 1,
    ]) );
    
    set("valid_startroom", 1);
        set("coor/x",-650);
        set("coor/y",-500);
        set("coor/z",40);
        setup();
        
    con = present("��ǽ",this_object());
/*      item= new(__DIR__"obj/cq2");
    item->move(con);
*/    
//      ��� is a very good weapon and has its significance in fy history.
//      However, too many ��� in game will only deflate its value and importance.
//      Therefore I commented it out to keep the number to be 3.
//      in 6666 main site this number has already been reached.
//      in us.fy site, if you are a wizard you can clone one and put it on wall.
//      keep a record of it and try to clone no more than 3 overall.
//                              --- silencer 4/10/2002 
} 
void init()
{
        add_action("climbing", "climb");
} 
void reset()
{
object me,me2;
:: reset();
me2=present("master li",this_object());
me=present("master liu",this_object());
if(me) me->dismiss_team();
if(me2) me2->dismiss_team();
if(me && me2) me->add_team_member(me2);
} 
int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "valley" || arg == "down" || arg == "�ȱ�")
        {
        me = this_player();
        message_vision("$Nץ��ͻ����ʯ�ǣ�������˳�Źȱ�������ȥ��\n", me);
        me->start_busy(7);
        call_out("fliping",7,me);
        me->stop_busy();
        return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}
int fliping(object me)
{
        if( !me->is_ghost()) {
        me->move(__DIR__"kuzhu");
        message_vision("$N˳�Źȱ�����������\n", me);
        }
        return 1;
}      
