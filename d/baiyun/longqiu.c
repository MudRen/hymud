 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������������ˮ���������죬��ǰ���·ת���Ӱɽ�⣻�����������ʺ��գ�
̶ˮ���������̻��죻�����滷ɽ��һ�߰�������ٲ���к���£���������������
��ˮ��ʮ������ȫ���̣�����������ǧ�ɣ�ˮ�������ѷ��ɡ�ɽ����������գ���
�����£�����һ���������̶֮�У�̶ˮȴ�����磬��һ�ɺ���ȴ�޿ײ��룬����
���衣
LONG
           );
        set("exits", 
           ([ 
       "north" : __DIR__"qingbi",
       "southwest" : __DIR__"shangu",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("outdoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}   
