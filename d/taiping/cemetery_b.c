 inherit ROOM;
void create()
{
        set("short", "�س�");
        set("long", @LONG
���Ҳҵ�ҹɫ�����������ҲҵĴ�أ���������������ʮ�׼����ķ�ڣ����
����ʯ��ʯ����Ȼ�����Ǹ����ĸ��𡣵�������ʯ��ʯ���Ѿ�ȱͷ���ȣ���ͷ��
�����˻Ĳݣ������߽�����ֻ��ѻ���ɵ�һ���ɢ��
LONG
        );
        set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);

        set("exits", ([
                "north" : __DIR__"cemetery6",
        ])); 
        setup();
}  
