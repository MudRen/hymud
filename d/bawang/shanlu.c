 inherit ROOM;
 
void create() 
{ 
        set("short", "ɽ��С��"); 
        set("long", @LONG 
һ�����ѵ�����С�������Է賤��ЩҰ��Ұ���������ɽ����ɢ��������Ѫ�� 
��ζ��ɽ��ҲԽ��Խ�󣬰�ãã��һƬ������������ɽ��·����Լ��ɿ������Ϸ� 
��Զ����һ�������� 
LONG); 
 
        set("type","road"); 
        set("exits",([ 
        "northwest":"/d/wudang/wdroad3",
        "southup":__DIR__"shanlu2", 
        ]) ); 
        set("outdoors", "bawang"); 
        set("coor/x",200);
        set("coor/y",-150);
        set("coor/z",0);
        setup(); 
        replace_program(ROOM); 
}     
