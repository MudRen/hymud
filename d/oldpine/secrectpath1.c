 // Room: /d/oldpine/secrectpath1.c
inherit ROOM; 
void create()
{
        set("short", "����ͨ��");
        set("long", @LONG
��������վ��һ����ʯͨ��֮�У����ϱ���������������ˮ������
��������������̦��һ�ɶ���ӱ��ߴ���������ʲ��Ұ�ޣ�Ҳ�����
��ͷ��ȥ�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"passage",
]));
        set("no_clean_up", 0); 
        set("coor/x",540);
        set("coor/y",2380);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}     
