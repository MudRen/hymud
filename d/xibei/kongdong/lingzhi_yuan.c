//1997-3-10 by qyz
#include <room.h>

inherit ROOM;



void create()
{
        set("short","��֥԰");
        set("long",@LONG
���������֥԰��԰ǽ�������һ�������ţ��ųʰ˽��Σ����а���ͼ����
�����ɺף�÷¹ͼ��ǽ�������á�˫��Ϸ�顱���ܣ����ռ��侫տ���ź�̡�
���Ժ����棬˫����Ǭ����һ����԰���滨��ݣ����෱�࣬����Ũ������ľ
��������ʦɢ��������Ϣ֮����ƽʱ�������˵���������
LONG);
        set("exits",
        ([
          "south" : __DIR__"xuanyuan_gong",
          "north" : __DIR__"lianhua_tai",
         
                ]));
       
        set("outdoors","kongdong");
        set("objects",([
                __DIR__"npc/shouyuan" : 1,
  __DIR__"npc/kdizi1" : 4 ,
                ]) );
        setup();
}
