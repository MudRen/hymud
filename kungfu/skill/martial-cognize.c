 // ��ѧ����

inherit SKILL;

int valid_learn(object me)
{
   if ( me->query("class") == "bonze" )
      return notify_fail("�����˲���ѧϰ��ѧ������\n");
    return 1;
//        return notify_fail("��ѧ����������ѧ����������޷�"
//                           "ͨ����ѧϰ���������\n");
}

int valid_research(object me)
{
        return notify_fail("��ѧ�����������ʵս���ļ�ȡ��"
                           "�գ��޷�ͨ���о�������\n");
}
