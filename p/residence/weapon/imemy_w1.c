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
	set_name("[1;31mº£ÑóÖ®±ø[2;37;0m", ({ "chungou sword", "sword" }));
	set_weight(16591);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[31m´¿¹³½«Ë§Ö®±ø£¬³ÖÖ®ÄÜ»Ó¾ü°ÙÍò£¬¿ËµĞÖÆÊ¤£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0mÖÆ³É£¬ÖØÈıÊ®Èı½ïÒ»Á½°ËÇ®µÄ[31m´¿¹³Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;36mÕ¶Ñı·üÄ§[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[37mÌì[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;31mÄ§[2;37;0m:[1;31m¿ªÔª[2;37;0m [1;33m½ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [32mË®[2;37;0m:[1;33mÌìÊ¥[2;37;0m [33mÍÁ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [1;34mµç[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÔ¨:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[1;34m¾ÙÊÀ[2;37;0m 
ÌåÁé:[1;34m¾ÙÊÀ[2;37;0m °×Ê¯:[35m±ê×¼[2;37;0m ×ÏÊ¯:[32m´Ö²Ú[2;37;0m ²»ÀÏ:[1;36mÍêÃÀ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¶É¶É[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÄÚ¹¦[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "imemy");
		set("ownername", "¶É¶É");
		set("value", 36000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",40);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",48);
		set("weapon_prop/dexerity",39);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 58);
    set("weapon_prop/parry", 36);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 89);
    set("weapon_prop/defense", 82);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 77);
    set("weapon_prop/jingli", 77);
    set("weapon_prop/damage", 0);

    set("wtypeA",8);
    set("wtypeB",6);
    set("wtypeC",10);
    set("wtypeD",6);
    set("wtypeE",10);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",12);
    set("wtypeI",11);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",13);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 26);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(711);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";