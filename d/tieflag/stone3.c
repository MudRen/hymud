 inherit ROOM;
#include <room.h>
void create()
{
        set("short", "�ص�");
        set("long", @LONG
�����Ǹ�Բ��ʯ��������������׺֮���ʣ����֮ëƤ������һ��һ�Σ�����
��ʯ��̶��ɣ���ɫ��ͬ�����߽��ġ��Ƕ�Ʈ��һ�󵭵��������������������
�����£�ʯ���ԣ��ͼ�ǰ����վ��ʮ�����������Ů�������е�������ɴ���е�
���Ž��ۣ��е�����̸Ц���е��������壬Ҳ�е�������ױ�����е�������ͼ��
LONG
        );
        set("exits",([
        
                "east" : __DIR__"stone2",
        
        ]) ); 
        set("objects",([
                __DIR__"obj/tieflag2" : 2,
                __DIR__"npc/o_girl" : 1,
                __DIR__"npc/b_girl" : 1,
                __DIR__"npc/r_girl" : 1,
        ]) );   
        create_door("east","����ʯ��","west",DOOR_CLOSED); 
        set("coor/x",2080);
        set("coor/y",-220);
        set("coor/z",-20);
        setup();
} 
