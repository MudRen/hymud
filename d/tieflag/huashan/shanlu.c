 inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
���������֣�һ��С·��������ǰ��ʯ���̾͵�ɽ·�϶�������ǰ���졣·��
ʯ����������һ��Ƭ��̦������֮�±���ʪ����̦��ʯ�����ˮ��һ�ελ�����
�£����������һ��СС��ʯ���
LONG
        );
    set("exits", ([ 
                "northeast" : __DIR__"ziqi",
            "westup" : __DIR__"yanluo",
        ]));
   
    set("outdoors", "huashanfy"); 
    set("coor/x",-600);
    set("coor/y",-100);
    set("coor/z",70);
        setup();
    replace_program(ROOM);
}  
