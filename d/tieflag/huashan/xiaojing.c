 inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
��·��Ȼ��խ������ɽ�Ƹ��Ը߾���С�������ڼз�����ǰ�����±�������ջ
��������ͨ����������ʱ�ڴ���Լ�ɼ�ջ���ϵ����ˡ����±������������ܣ�����
�����¸��ʣ��쿪һ�ߣ�����׳�ۡ� 
LONG
        );
    set("exits", ([ 
                "north" : __DIR__"shanmen",
                "southup" : __DIR__"zhuyu",
        ]));
   
    set("outdoors", "huashanfy"); 
    set("coor/x",-560);
    set("coor/y",-25);
    set("coor/z",0);
        setup();
    replace_program(ROOM);
}     
