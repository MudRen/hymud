#include <ansi.h>;
inherit ROOM; 
void create()
{
        set("short", "��ȸ��");
        set("long", @LONG
�ݴ���¥���ĳǳء���Ժ�ʹ����㲼�ڿ�ȸ����������������Ҳԭ��������
�ĵĺ�����ǧ����ǰҲ������һ���̴����ڲ�ԭ�����ѣ������һ�ж����ǹ�����
�ƣ����յĳ����ֽ񲻸����ڣ�ֻ����Ҳ��ͬ���һ����ɳ�������յĺӵ�������
���ʣ���֪ͨ��η�������
LONG
        ); 
        set("exits", ([ 
                "southeast" : __DIR__"yangguan",
        "northwest" : "/d/xibei/desert/loulan2",
        ]));
        set("outdoors", "loulan");
        set("objects", ([
                __DIR__"npc/xiongmaoer" : 1,
        ]) );
        set("item_desc", ([
                "ɳ��": "
��ȸ���н�����ɳʯ������ƽ�����㣬��������ҫ�۶�Ŀ��ϸϸ��ȥ��ɳ��
�ƺ��ڻ�����������֪���ܲ����ˣ�WADE����ȥ���� ��\n",
                "sandstream": "
��ȸ���н�����ɳʯ������ƽ�����㣬��������ҫ�۶�Ŀ��ϸϸ��ȥ��ɳ��
�ƺ��ڻ�����������֪���ܲ����ˣ�WADE����ȥ���� ��\n",
        
        ]) );
        set("coor/x",-1000);
        set("coor/y",200);
        set("coor/z",0);
        setup();
} 
 void init()
{
        add_action("do_wade","wade");
} 
int do_wade(string arg)
{
        object room;
        object me;  
        me=this_player();
        switch (arg)
        {
                case "ɳ��":
                case "sandstream":
                        if(!objectp(room = find_object(__DIR__"sandstream")))
                        room = load_object(__DIR__"sandstream");
                        message_vision("$NС������Ƚ�ɳ����......\n",this_player());
                        me->move(room);
                        return 1;
        }
         
}  
