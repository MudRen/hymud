 inherit ROOM;
void create()
{
        set("short", "��ɼ����");
        set("long", @LONG
���������ʸ���һ����ɼ���ϣ���Ҷ���ܣ�����������Ҳ͸����ï�ܵ����ڡ�
��������Ժ�������������µ�һ�ж������������˷������ƺ��Ǹ���͵������
�����ĺõط������ںܴ�һ������֦���������˸�����Ժ���
LONG
        );
        set("objects", ([
                __DIR__"npc/banditspy" : 1,
        ]) ); 
        set("exits", ([ /* sizeof() == 2 */
                "down" : __DIR__"groad3",
        ])); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init()
{
        add_action("do_jump", "jump");
        add_action("do_jump1", "jumpdown");
} 
int do_jump(string arg)
{
        object me, room; 
        me = this_player();
        if(!arg || arg != "down") return 0;
        if (me->is_busy()|| me->is_fighting()) {
                tell_object(me,"��������æ��\n");
                return 1;
                }
        message_vision("$N�����ϰ��������ƮƮ���䵽��Ժ�ڡ�\n\n", me);
        room = find_object(__DIR__"backyard"); 
        if(!objectp(room)) room=load_object(__DIR__"backyard");
        me->move(room);
        message("vision",me->name()+"��ƮƮ���䵽��Ժ�ڡ�\n", environment(me), me); 
           return 1;
} 
int do_jump1(string arg)
{
        object me, room; 
        me = this_player();
        if (me->is_busy()|| me->is_fighting()) {
                tell_object(me,"��������æ��\n");
                return 1;
                }
        message_vision("$N�����ϰ��������ƮƮ���䵽��Ժ�ڡ�\n\n", me);
        room = find_object(__DIR__"backyard"); 
        if(!objectp(room)) room=load_object(__DIR__"backyard");
        me->move(room);
        message("vision",me->name()+"��ƮƮ���䵽��Ժ�ڡ�\n", environment(me), me); 
        return 1;
}      
