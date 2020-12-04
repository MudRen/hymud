 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
�����ഫ��Ů洲�ʯ������ȡ����ɽʯ�о�Ӣ���ڣ�ɽɫ���ɽ���죬������
��ɫ��ɽ����ľҲ����ï�ܣ�ɽ�����ƣ��������˵��ɹ��ֺ������ߣ���֮����
ɽ�ٻ��ƣ��������ߣ������������˵��ˡ�ԶԶ������ԯ�壬ȴ��������ȥ��
LONG
        );
        set("exits", ([ 
                "southdown" : __DIR__"sroad",
                "north" : __DIR__"xuanyuan",
        ]));
        set("objects", ([
                __DIR__"npc/dizi2" : 1,
        ]) );
    
    
        set("stone_amount", 2);
        set("outdoors", "huangshan");
        set("coor/x",-650);
        set("coor/y",-530);
        set("coor/z",40);
        setup();
} 
void init()
{
        add_action("do_chop","chop");
}  
int do_chop(string arg)
{
    object obj, me;
    if(!arg || arg=="") return notify_fail("��Ҫ����ʲô��\n");
    if( arg == "vine" || arg == "ɽ��")
        {
        me = this_player();
        obj = me->query_temp("weapon");
        if( !obj )
        {
        write("������֣���ô����\n");
        return 1;
        }
        if( random(5)==0)
        {
        if( !query("exits/north") ) {
        set("exits/north", __DIR__"xuanyuan");
        message_vision(sprintf("$N�����е�%s����һ���򱱵�·��\n",obj->name()),
                me);
        me->start_busy(1);
        }
        else
        message_vision(sprintf("$N�����е�%s�����Ƶ�ɽ�٣�\n",obj->name()),
                me);
        }
        else
        message_vision(sprintf("$N�����е�%s�����Ƶ�ɽ��һ���ҿ���\n",obj->name()),
                me);
        }
        else
         write("��Ҫ����ʲô��\n");
                return 1;
} 
int dig_notify() {
        object me, item;
        int i;
        
        me = this_player();
        i = random(10); 
        if(me->is_busy()) { 
                write("����������æ��\n");
                return 1;
        }
        if(me->is_fighting()) return 0;
        if( i == 4 ) {
                write("������������һ�٣���Ӳ����������㻢�ڷ�ʹ��\n");
                message("vision", me->name() + "����һ�٣�ֻ�����ϡ���������һ��������ȴ˿��δ��\n",
                                environment(me), me);
        } else {
           if (random(10) > 7 && query("stone_amount") >= 0) {
                        message_vision("$N����������һ�١�\n", me);
                        write("�㷢��һ��������õ�ʯͷ��\n");
                        if (random(10) > 7) {
                                item = new(__DIR__"obj/xishi2");
                                item->move(this_object());
                        } else {
                                item = new(__DIR__"obj/xishi");
                                item->move(this_object());
                        }
                        add("stone_amount", -1);
                } else {
                        write("���ڵ������˸���ӣ�ʲôҲû���ҵ���\n");
                }       
        }
        me->start_busy(1);
}  
void reset() {
        ::reset();
        if (!random(4)) set("stone_amount", 2);
        delete("exits/north");
}
