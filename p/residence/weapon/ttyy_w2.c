// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[1;36m����֮��[2;37;0m", ({ "kunlun sword", "sword" }));
	set_weight(12618);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[1;36m	Ц�����˼�ʮ���Σ��ո�����ͷ��
	��ͭ���ﲴ���������죬�������ƣ� 
	����ʫ���ζϣ��Ϲ����� 
	�ѽ���Ȼ�����޴��й��ۡ� 
 
	��������·Զ����˭�����壬ŪӰ���ޣ�
	��Ӣ�۶�Ů�������Ž�
	�����ܵƻ����ʣ���꼻�һ�ֺ����ݣ�
	Ʈ��ߣ��������ƴ����� 
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m�Ƴɣ��ض�ʮ��������Ǯ��[1;36m����֮��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȷ���������[1;31m������˫[2;37;0m��������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;34m����[2;37;0m [40m��[2;37;0m:[1;35m����[2;37;0m [1;31mħ[2;37;0m:[1;34m����[2;37;0m [36mľ[2;37;0m:[1;33m��ʥ[2;37;0m [33m��[2;37;0m:[1;33m��ʥ[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[34mϸ��[2;37;0m ����:[32m�ֲ�[2;37;0m 
��ʯ:[32m�ֲ�[2;37;0m ��ʯ:[35m��׼[2;37;0m ����:[32m�ֲ�[2;37;0m 
����:[32m�ֲ�[2;37;0m ����:[35m��׼[2;37;0m ����:[33m�ܸ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����ԲԲ[2;37;0m ������һЩ�� [1;32m�޷�[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ttyy");
		set("ownername", "����ԲԲ");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",25);
		set("weapon_prop/dexerity",48);
		set("weapon_prop/constitution",48);
    set("weapon_prop/dodge", 32);
    set("weapon_prop/parry", 54);
    set("weapon_prop/attack", 31);
    set("weapon_prop/armor", 34);
    set("weapon_prop/defense", 56);
    
    set("weapon_prop/neili", 36);
    set("weapon_prop/qi", 48);
    set("weapon_prop/jing", 52);
    set("weapon_prop/jingli", 52);
    set("weapon_prop/damage", 43);

    set("wtypeA",0);
    set("wtypeB",10);
    set("wtypeC",0);
    set("wtypeD",6);
    set("wtypeE",10);
    set("wtypeF",6);
    set("wtypeG",0);
    set("wtypeH",6);
    set("wtypeI",8);
    set("wtypeJ",11);
    set("wtypeK",4);
    set("wtypeL",8);
    

                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 16);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(1287);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";