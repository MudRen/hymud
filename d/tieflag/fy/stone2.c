 // Tie@fengyun
#include <room.h> 
inherit ROOM;
void create()
{
        set("short", "ʯ�ﾡͷ");
        set("long", @LONG
ʯ�ﲻ��ܿ쵽�˾�ͷ��һ�¸�ǽ��סȥ·��ǽ���е�խ�ţ�ǽ����һ������
һ����ϡϡ��С�ӹ��ӹ�����������ʱ����ʱ�ģ�һ��������Ѫˮ�ı����ӹ�����
������ɢ������������ζ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"stone1",
  "north" : __DIR__"sroom",
])); 
        set("objects", ([
                __DIR__"npc/newsman" : 1,
        ]));
        set("outdoors", "fengyun");
        set("coor/x",10);
        set("coor/y",20);
        set("coor/z",0);
        setup(); 
        create_door("north", "ľ��", "south", DOOR_CLOSED); 
} 
// this code work only if npc cannot be arrested.
int invalid_leave(object me)
{
        object ob;
        if(  me->query_temp("answer_questions") <= 3 ) 
        {
                me->delete_temp("score");
                me->delete_temp("answer_questions");
                me->delete_temp("num_question");
                me->delete_temp("in_ask");
                if(ob=present("news man", this_object()))
                {
                        ob->set("in_test",0);
                }
        }
        return 0;
}       
