// yaopai.c

#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
	set_name("����", ({ "yao pai", "yaopai" }));
	set("long", "����һ��������ơ�\n"+
"    ƾ�����ƣ���������(tisheng) �ͽ���(jiangchu)�����������
�������ڣ�������������(quzhu) ����ᡣ����������ʧһ������
����������Ա����ʮ��ʧ�������������˳�(tuichu)������ᣬ��
��һ���Ĵ���������
     ��(�š���)���޷��˻ᡣ��������λ(rangwei) ��������ڣ�
�������ˡ�����Υ�����ѵ�������������ʱ�ɳ���������õ�ִ����
��ǰ���ʹ�(chengchu)��
    ���������һλ�Ǳ������Ա��Ϊ����һ�����ڣ���������Ϊ��
ʾ�ҳ�֮���ģ������ȸ�һ���Դ�������Ϊ����Ͷ��״��
    ��������˵Ⱦ��ܻ��һ�����ƣ������Լ���Ȩ��ƾ������ʹ��
��Ȩ����
      ��(���)��    ���� ���� �ʹ� ���� ���� ���� ��λ
      ����(���)��  ���� ���� �ʹ� ���� �˳�
      ����            ���� ���� �ʹ� �˳�
      ����            ���� ���� �˳�
      ����            �˳�
      һ������        �˳�
���е������ġ���ײ��˵ȿ�������(renming)ר�����紫�����ϡ�
�������������������ȵȡ��κ��˵Ⱦ�����party������ı������
����
    ������Ҷ�ʧ�����ƣ����Ե����ֶ��Źط������Ϳ�ͷ(ketou)��
�ú�˼����
\n");
	set("weight", 300);
	set("no_get", 1);
	set("no_get_from", 1);
	set("no_give", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("material", "��");
	}
	setup();
	init_dagger(555);
}
