#include <ansi.h> 
#include <armor.h>

inherit HEAD;

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

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;32m�޼�֮ͷ��[2;37;0m", ({ "wuji head", "head" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;32m�����Ѵ�����뻯���Ƿ��켫���������֮���磡��˵������ڣ������⡰�޼�����
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m����[37m���˿[2;37;0m�Ƴɣ�������һ����Ǯ��[1;32m�޼�֮ͷ��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;31m��˫[2;37;0m [36mľ[2;37;0m:[31m����[2;37;0m [1;35m��[2;37;0m:[1;31m��˫[2;37;0m 
[1;37m��[2;37;0m:[1;31m��˫[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[32m�ֲ�[2;37;0m 
����:[34mϸ��[2;37;0m 
����:[35m��׼[2;37;0m ����:[35m��׼[2;37;0m ����:[35m��׼[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "����");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",40);
		set("armor_prop/karey",48);
		set("armor_prop/percao",32);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 40);
    set("armor_prop/parry", 48);
    set("armor_prop/attack", 25);


    set("armor_prop/armor", 456);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 50);
    set("armor_prop/qi", 59);
    set("armor_prop/jing", 57);
    set("armor_prop/jingli", 57);
    set("armor_prop/damage", 59);

    set("wtypeA",12);
    set("wtypeB",6);
    set("wtypeC",3);
    set("wtypeD",6);
    set("wtypeE",4);
    set("wtypeF",12);
    set("wtypeG",12);
    set("wtypeH",5);
    set("wtypeI",6);
    set("wtypeJ",6);
    set("wtypeK",5);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";