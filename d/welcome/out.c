// Room: /d/welcome/newbie3
inherit ROOM;

void create ()
{
  set ("short", "�����ĳ���");
  set ("long", @LONG
���������Ĵ��ţ�̤����������򽭺��ˡ�����ǵöౣ�����
����(save),����������뿪��(quit),�����ĵط����Կ�(help),ף��
�����졣������12��·�ֱ�ͨ��
yz ���� bj ���� xy ���� dl ���� lz ���� xz ����
qz Ȫ�� wg ��� jp �ձ� cd �ɶ� km ���� xj �½�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "yz" : "/d/city/kedian",
  "bj" : "/d/beijing/kedian",
  "xy" : "/d/xiangyang/kedian",
  "dl" : "/d/dali/kedian",
  "qz" : "/d/quanzhouchen/kedian",
  "wg" : "/d/wuguan/guanmen",
  "jp" : "/d/japan/dongmen",
  "cd" : "/d/chengdu/kedian",
  "lz" : "/d/lanzhou/kedian",
  "km" : "/d/kunming/kedian",		
  "xz" : "/d/xizang/octostreet",		
  "xj" : "/d/xinjiang/nanmen",	
]));
  set("no_magic", 1);
  set("no_beg",1);
  set("pingan",1);
  set("no_fight", 1);
  set("pingan", 1);
  set("chatroom",1);
  setup();
}
