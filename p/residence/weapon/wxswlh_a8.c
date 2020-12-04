#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[31m´¿¹³Ö®¶Ü[2;37;0m", ({ "chungou shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ãæ");
		set("long", @LONG
[31m´¿¹³½«Ë§Ö®±ø£¬³ÖÖ®ÄÜ»Ó¾ü°ÙÍò£¬¿ËµĞÖÆÊ¤£¡
[2;37;0mÕâÊÇÒ»ÃæÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0m¼ÓÉÏ[1;33mÁú¼ë²ÏË¿[2;37;0mÖÆ³É£¬ÖØËÄ½ïËÄÁ½ËÄÇ®µÄ[31m´¿¹³Ö®¶Ü[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[37mÌì[2;37;0m:[1;36mÍêÃÀ[2;37;0m [36mÄ¾[2;37;0m:[1;31m¿ªÔª[2;37;0m [32mË®[2;37;0m:[1;31mÎŞË«[2;37;0m [1;35m·ç[2;37;0m:[1;31m´´ÊÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;33mÃğÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÌìÁé:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
°×Ê¯:[1;36mÍêÃÀ[2;37;0m ÉÁµç:[35m±ê×¼[2;37;0m 
ÖÜÌì:[1;34m¾ÙÊÀ[2;37;0m ³¤Éú:[1;32mÄ§Íõ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÄ½Èİ´ó[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÆ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wxswlh");
		set("ownername", "Ä½Èİ´ó");
		set("value", 36000);
		set("armor_prop/intelligence",36);
		set("armor_prop/strength",0);
		set("armor_prop/karey",32);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 79);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 55);


    set("armor_prop/armor", 405);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 81);
    set("armor_prop/qi", 90);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 8);
    set("armor_prop/damage", 37);

    set("wtypeA",3);
    set("wtypeB",13);
    set("wtypeC",12);
    set("wtypeD",3);
    set("wtypeE",0);
    set("wtypeF",14);
    set("wtypeG",16);
    set("wtypeH",0);
    set("wtypeI",7);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 24);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";