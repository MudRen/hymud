 inherit ROOM;
void create()
{
        set("short", "Ԫ����");
        set("long", @LONG
Ԫ����λ�ڶ����̶��������ڻ����������ϴ��顰���ɽ�����׳���Ůɽ��
��ɽ��ƽ̹����Ң���Ǵˣ�������Ң��̨��������Χ��������֮�١���Ů��
�洦������ͬ�������������������̨���Դ䡱��������˼�ʡ�ʯ���Ƽ䡱����̡�
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"shiba",
  "west" : __DIR__"shanfeng",
  "north" : __DIR__"houshi",
  "east" : __DIR__"bixia",
])); 
        set("item_desc", ([
                "ʯ��": "               
                ��              ��
                ��              ��
                ��              ��
                ��              ��
                ��              ��
                ��              ��
                ǧ              ��
                ��              ��
                ��              ʤ
                ��              ��
                 ��              ��                     
"        ]) );
        set("objects", ([
        __DIR__"npc/pettrainer" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",320);
        set("coor/y",2390);
        set("coor/z",120);
        setup();
        replace_program(ROOM);
}   
