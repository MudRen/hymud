 // Room: dong0
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "ɽ�ȿ�");
        set("long", @LONG
һƬ������ɽ�ȣ���ɽ�ϱ����Է�δ䣬һ����Ϫ��������ˮ
�����ܣ������������Ϫһ�������������˿���ƣ���Ϫ�԰���
���·����䣬�����ֳ�һ�����ᣬ���⻨֦���ƣ������ƽ���
LONG
        ); 
       set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"gu",
  "north" : __DIR__"gu1",
 
]));
     
        set("outdoors","tieflag");          
      set("coor/x",120);
        set("coor/y",0);
        set("coor/z",5);
        setup();
        replace_program(ROOM); 
}       
