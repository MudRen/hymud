// Room: d/kyoto/yuzhidaochang
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "���ε���");
set("long", @LONG
������Ǻպ����������ε������������˾�ͨ���¸�����ѧ�����µ���
��ǧ���б��������궼Ͷ������ϰ�䣬ϣ���г�һ�ճ�Ϊ��ѧ̩���������
��ʦ������ڸ��ֻ������书���Ǹ�ǿ������ĺõط������ͶԵ�����˱�
�����������ҵ�����������Ĵ��˹�С���ɣ����ݵ�Ļ�����䣬Ļĩʱ��
糴彣�ĵ���˾���������֣���                    .
LONG );
set("exits",  ([
        "south"  : __DIR__"heyuanting3",
      ]));
        setup();
        replace_program(ROOM);
}