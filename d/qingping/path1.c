 inherit ROOM;
void create()
{
        set("short", "��ҰС��");
        set("long", @LONG
С·���ѵ�����Զ�����������֣�С·�������Ĳ���û��Ҳ�治���ۼ�������
����ľȴԽ��Խ�ܼ�����û��������գ�ȴ���˸е�һ����ɭɭ�ӽ���������Ϣ��
���������񶼺�ϡ�٣�����Ҫ˵�����١�
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
           "west" : __DIR__"path",      
                "east" : __DIR__"forest1",
   ]));
        set("outdoors","qingping");
        set("coor/x",220);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
