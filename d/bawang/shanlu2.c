 inherit ROOM;
 
void create() 
{ 
    set("short", "����С��");
 
        set("long", @LONG 
һ�����ѵ�����С�������Է賤��ЩҰ��Ұ���������ɽ����ɢ��������Ѫ�� 
��ζ��ɽ��ҲԽ��Խ�󣬰�ãã��һƬ������������ɽ��·����Լ�ɼ���Զ������ 
�þ����ĺ������Ӱ�ӡ������ƺ�����Ӱ�ζ��� 
LONG); 
 
        set("type","road"); 
        set("exits",([ 
        "southup":__DIR__"ehugang",
        "northdown":__DIR__"shanlu",
        ]) ); 
        set("outdoors", "bawang"); 
        set("coor/x",200);
        set("coor/y",-160);
        set("coor/z",20);
        setup(); 
        replace_program(ROOM); 
}       
