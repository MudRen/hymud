#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "���Ƹ�");
        set("long", @LONG
���Ƹ�����˾��ǵ������´���������С��ɵ�����Ȼ��̽���Ѿ����˶�ʱ��
���ǻ��п���Ľ�������˸�����һ��֮Ե�����д�첨˹��̺�̵أ������ûʡ�
���Ĵ����������һ��ʯ�̵Ķ�������
                        һ���߽�ʿ
                        ������̽��
LONG
        );
        set("valid_startroom", 1);
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
        
        set("exits", ([
                "west"          : __DIR__"nwind1",
                "up"            : __DIR__"fyyage",
        ]) ); 
        set("objects", ([
                __DIR__"npc/fywaiter" : 1, 
                        ]) );  
        set("coor/x",10);
        set("coor/y",10);
        set("coor/z",0);
        setup(); 
        // To "load" the board, don't ever "clone" a bulletin board.
//        call_other( "/obj/board/common_fy", "???" );
} 
string look_sign(object me)
{
        if( wizardp(me) )
                return "����д�������Ƹ��Ա�һ��С�֣������⡣\n";
        else
           return "����д�������Ƹ�\n";
}   
