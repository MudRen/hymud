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
	      set_name("[34mÆßĞÇÖ®Í·¿ø[2;37;0m", ({ "qixing head", "head" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
		set("long", @LONG
[34mÆßĞÇÖ®Í·¿ø[2;37;0mÕâÊÇÒ»¶¥ÓÉÎŞ±È¼áÓ²µÄ[1;33m½ğÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØÈı½ïÁãÁ½¾ÅÇ®µÄ[34mÆßĞÇÖ®Í·¿ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[36m²»Ğ¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[1;31mÎŞË«[2;37;0m [33mÍÁ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;31mÎŞË«[2;37;0m [1;34mµç[2;37;0m:[1;35m¾øÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31mÎŞË«[2;37;0m ¸£Ô´:[34mÏ¸Ëé[2;37;0m 
ÇÉÖÆ:[34mÏ¸Ëé[2;37;0m 
×ÏÊ¯:[34mÏ¸Ëé[2;37;0m ÉÁµç:[32m´Ö²Ú[2;37;0m 
³¤Éú:[32m´Ö²Ú[2;37;0m ²»ÀÏ:[33mºÜ¸ß[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÊ·µÙ·ÒÖÜ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m±Ş·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xianoda");
		set("ownername", "Ê·µÙ·ÒÖÜ");
		set("value", 16000);
		set("armor_prop/intelligence",32);
		set("armor_prop/strength",40);
		set("armor_prop/karey",21);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",16);
		set("armor_prop/constitution",8);
    set("armor_prop/dodge", 24);
    set("armor_prop/parry", 26);
    set("armor_prop/attack", 32);


    set("armor_prop/armor", 250);
    set("armor_prop/defense", 16);
    
    set("armor_prop/neili", 24);
    set("armor_prop/qi", 36);
    set("armor_prop/jing", 46);
    set("armor_prop/jingli", 46);
    set("armor_prop/damage", 106);

    set("wtypeA",0);
    set("wtypeB",12);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",8);
    set("wtypeF",7);
    set("wtypeG",12);
    set("wtypeH",11);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";