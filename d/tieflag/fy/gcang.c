 inherit ROOM;
void create()
{
        set("short", "�ھֻ���");
        set("long", @LONG
��ʨ�ھ������������죬��δʧ�ڡ������Ļ���������ѻ���ɽ���ھֵĻ��
��������æ���ҵ����ڳ���װ�ػ����Ȼÿ����ƶ�����ͷ�󺹣�������Ϊ����
����æ��������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"goldlion",
]));
        set("objects", ([
        __DIR__"npc/huoji" : 2,
        __DIR__"npc/bad_huoji" : 1,
                        ]) ); 
        set("coor/x",10);
        set("coor/y",50);
        set("coor/z",0);
        set("coor/x",10);
        set("coor/y",50);
        set("coor/z",0);
        setup();
}
void init()
{
        add_action("do_work", "work");
}
int do_work(string arg)
{
        object ob;
        object me; 
        me = this_player(); 
message_vision("$N���ھֵĻ�����ڳ���װ�ػ�����������ۣ���\n",me);
me->add("gin",-30);
me->add("sen",-30);
me->set("marks/��ʨ", time());
return 1;
}  
