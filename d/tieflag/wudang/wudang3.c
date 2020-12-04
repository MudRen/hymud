 inherit ROOM;
void create()
{
    set("short", "��Ժ");
    set("long", @LONG
Ժ���ĽǸ�����һ�����������������һ��ˮ������ʯ���̳ɵ�
���棬û���κ��Ӳ���Ҷ��Ժ��������һ���᷿������������������
ʱ�������������ȭ���������洫������
LONG
        );
    set("exits", ([ 
        "out" : __DIR__"wuroad4",
        "north" : __DIR__"wudang4",
        "south" : __DIR__"wudang5",
        ]));
    set("item_desc", ([
        "jing": "�䵱�����ճ��õ�ˮ�������ƺ�����������(enter)��ȥ��\n",
        "well": "�䵱�����ճ��õ�ˮ�������ƺ�����������(enter)��ȥ��\n",
        "��": "�䵱�����ճ��õ�ˮ�������ƺ�����������(enter)��ȥ��\n",
        ]) );
    set("resource/water",1);
    set("objects", ([
                __DIR__"npc/taoist7" : 1,
    ]));
    
    set("outdoors", "wudangfy");
    set("coor/x",150);
    set("coor/y",-130);
    set("coor/z",50);
    setup();
} 
void init()
{
    add_action("do_enter", "enter");
} 
int do_enter(string arg)
{
    object obj;
    object me; 
    if(!arg || arg=="")
    {
        write("��Ҫ�������ꣿ\n");
        return 1;
    }
    me = this_player();
    if( arg == "jing" || arg == "well" || arg == "��")
    {
        message_vision("$N�����ܿ���һ������û��ע�⣬����һ��������˾��\n", me);
        me->move(__DIR__"jing.c");
        return 1;
    }
    else
    {
        write("�㲻������"+arg+"���꣡\n");
        return 1;
    }
} 
int valid_leave(object me,string dir)
{
        object ob;
        if(userp(me) && me->query("class")!="wudang" 
                &&(dir == "north" ||dir=="south") && ob=present("guo",this_object()))
        {
        message_vision("$N��$n�����䵱����,�ǵ��Ӳ��ܽ���!\n",ob,me);
        return notify_fail("");
        }
        return 1;
}     
