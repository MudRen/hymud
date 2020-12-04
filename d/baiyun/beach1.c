  //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
inherit ROOM;
void create()
{
        set("short", "ɳ̲");
        set("long", @LONG
��������ѷֲ��������˼䡣������ã�ɳ̲�����ϸ����ˮտ����̣�����
�������������İ�ĭ�����ź�������Ŀ�������������죬�����к������ӱ̿գ�����
�����׺��������ᷫ��ɳ̲�ϰڷ��ż�����������������ҹ�������һ���޲�������
һ�ߺ������С������ˮ�����£������ɳ��̤��ȥ���������
LONG
           );
        set("exits", 
           ([ 
             "west" : __DIR__"beach3",
             "east"  : __DIR__"beach",
            ]));
        set("item_desc", 
           ([
             "��ˮ": "͸���峺�����ĺ�ˮ������Կ�����ˮ����Ϸ����Ϻ���������������������ĺ��塣\n",
             "seawater":"͸���峺�����ĺ�ˮ������Կ�����ˮ����Ϸ����Ϻ�������������˲��������ĺ��塣\n",
            ]));
        set("objects", 
           ([ 
             __DIR__"obj/sand" : 1,
             __DIR__"npc/fishman" : 1,
         __DIR__"npc/fishwoman" : 1,
            ]));
        set("littlething", 10);
    set("outdoors", "baiyun");
    set("coor/x",-10);
        set("coor/y",-680);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_dive", "dive");
    add_action("do_search", "search");
} 
int do_search(string arg)
{
        object me, obj, sand;
        me = this_player();
        sand = present("sand", this_object());
        if(!arg) {
            write("��Ҫ�������Ҷ�����\n");
            return 1;
        }
        if( me->is_busy() ) {
            return notify_fail("����һ��������û����ɣ�����������\n");
        }
        if( arg == "sand" || arg == "ɳ��"  ){
            if ( query("littlething") > 0 && !random(3) ) {
                        message_vision("$N�������ӣ���ɳ������Ѱ�ţ�ͻȻ��ɳ���ڳ���С���⡣\n",me);
                        obj = new(__DIR__"obj/littlething");
                        obj->move(environment(me));
                        add("littlething", -1);
            } else {
            message_vision("$N���ͷ��ķ��˰��죬��ʲô��û���ҵ���\n",me);
            me->start_busy(3);
            }
        }
        return 1;
}
void reset()
{
        ::reset();
        set("littlething", 25);
} 
